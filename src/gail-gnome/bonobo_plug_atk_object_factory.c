/*
 * LIBGAIL-GNOME -  Accessibility Toolkit Implementation for Bonobo
 * Copyright 2001 Sun Microsystems Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <gtk/gtkwidget.h>
#include <libspi/Accessibility.h>
#include "bonobo_plug_atk_object.h"
#include "bonobo_plug_atk_object_factory.h"


static void bonobo_plug_atk_object_factory_class_init (
                                BonoboPlugAtkObjectFactoryClass        *klass);

static AtkObject* bonobo_plug_atk_object_factory_create_accessible (
                                GObject                       *obj);

static GType bonobo_plug_atk_object_factory_get_accessible_type (void);

GType
bonobo_plug_atk_object_factory_get_type (void)
{
  static GType type = 0;

  if (G_UNLIKELY (!type))
  {
    const GTypeInfo tinfo =
    {
      sizeof (BonoboPlugAtkObjectFactoryClass),
      (GBaseInitFunc) NULL, /* base init */
      (GBaseFinalizeFunc) NULL, /* base finalize */
      (GClassInitFunc) bonobo_plug_atk_object_factory_class_init, /* class init */
      (GClassFinalizeFunc) NULL, /* class finalize */
      NULL, /* class data */
      sizeof (BonoboPlugAtkObjectFactory), /* instance size */
      0, /* nb preallocs */
      (GInstanceInitFunc) NULL, /* instance init */
      NULL /* value table */
    };
    type = g_type_register_static (ATK_TYPE_OBJECT_FACTORY, 
                           "BonoboPlugAtkObjectFactory" , &tinfo, 0);
  }

  return type;
}

static void 
bonobo_plug_atk_object_factory_class_init (BonoboPlugAtkObjectFactoryClass *klass)
{
  AtkObjectFactoryClass *class = ATK_OBJECT_FACTORY_CLASS (klass);

  class->create_accessible   = bonobo_plug_atk_object_factory_create_accessible;
  class->get_accessible_type = bonobo_plug_atk_object_factory_get_accessible_type;
}

AtkObjectFactory*
bonobo_plug_atk_object_factory_new (void)
{
  GObject *factory;

  factory = g_object_new (BONOBO_TYPE_PLUG_ATK_OBJECT_FACTORY, NULL);

  return ATK_OBJECT_FACTORY (factory);
} 

static AtkObject* 
bonobo_plug_atk_object_factory_create_accessible (GObject *obj)
{
  g_return_val_if_fail (BONOBO_IS_PLUG (obj), NULL);

  return bonobo_plug_atk_object_new (BONOBO_PLUG (obj));
}

static GType
bonobo_plug_atk_object_factory_get_accessible_type (void)
{
  return BONOBO_TYPE_PLUG_ATK_OBJECT;
}

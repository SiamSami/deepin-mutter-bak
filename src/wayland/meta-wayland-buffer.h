/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*- */

/*
 * Copyright (C) 2014 Endless Mobile
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 * Written by:
 *     Jasper St. Pierre <jstpierre@mecheye.net>
 */

#ifndef META_WAYLAND_BUFFER_H
#define META_WAYLAND_BUFFER_H

#include <cogl/cogl.h>
#include <cairo.h>
#include <wayland-server.h>

#include "meta-wayland-types.h"

struct _MetaWaylandBuffer
{
  GObject parent;

  struct wl_resource *resource;
  struct wl_listener destroy_listener;

  CoglTexture *texture;
};

#define META_TYPE_WAYLAND_BUFFER (meta_wayland_buffer_get_type ())
G_DECLARE_FINAL_TYPE (MetaWaylandBuffer, meta_wayland_buffer,
                      META, WAYLAND_BUFFER, GObject);

MetaWaylandBuffer *     meta_wayland_buffer_from_resource       (struct wl_resource    *resource);
CoglTexture *           meta_wayland_buffer_ensure_texture      (MetaWaylandBuffer     *buffer);
void                    meta_wayland_buffer_process_damage      (MetaWaylandBuffer     *buffer,
                                                                 cairo_region_t        *region);

#endif /* META_WAYLAND_BUFFER_H */

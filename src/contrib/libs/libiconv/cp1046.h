/* The following code is the modified part of the libiconv
 * available at http://www.gnu.org/software/libiconv/
 * under the terms of the GNU Lesser General Public License v. 2
 * http://www.gnu.org/licenses/lgpl.html
 */

/*
 * Copyright (C) 1999-2001 Free Software Foundation, Inc.
 * This file is part of the GNU LIBICONV Library.
 *
 * The GNU LIBICONV Library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * The GNU LIBICONV Library is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with the GNU LIBICONV Library; see the file COPYING.LIB.
 * If not, write to the Free Software Foundation, Inc., 51 Franklin Street,
 * Fifth Floor, Boston, MA 02110-1301, USA.
 */

/*
 * CP1046
 */

static const unsigned short cp1046_2uni[128] = {
  /* 0x80 */
  0xfe88, 0x00d7, 0x00f7, 0xf8f6, 0xf8f5, 0xf8f4, 0xf8f7, 0xfe71,
  0x0088, 0x25a0, 0x2502, 0x2500, 0x2510, 0x250c, 0x2514, 0x2518,
  /* 0x90 */
  0xfe79, 0xfe7b, 0xfe7d, 0xfe7f, 0xfe77, 0xfe8a, 0xfef0, 0xfef3,
  0xfef2, 0xfece, 0xfecf, 0xfed0, 0xfef6, 0xfef8, 0xfefa, 0xfefc,
  /* 0xa0 */
  0x00a0, 0xf8fa, 0xf8f9, 0xf8f8, 0x00a4, 0xf8fb, 0xfe8b, 0xfe91,
  0xfe97, 0xfe9b, 0xfe9f, 0xfea3, 0x060c, 0x00ad, 0xfea7, 0xfeb3,
  /* 0xb0 */
  0x0660, 0x0661, 0x0662, 0x0663, 0x0664, 0x0665, 0x0666, 0x0667,
  0x0668, 0x0669, 0xfeb7, 0x061b, 0xfebb, 0xfebf, 0xfeca, 0x061f,
  /* 0xc0 */
  0xfecb, 0x0621, 0x0622, 0x0623, 0x0624, 0x0625, 0x0626, 0x0627,
  0x0628, 0x0629, 0x062a, 0x062b, 0x062c, 0x062d, 0x062e, 0x062f,
  /* 0xd0 */
  0x0630, 0x0631, 0x0632, 0x0633, 0x0634, 0x0635, 0x0636, 0x0637,
  0xfec7, 0x0639, 0x063a, 0xfecc, 0xfe82, 0xfe84, 0xfe8e, 0xfed3,
  /* 0xe0 */
  0x0640, 0x0641, 0x0642, 0x0643, 0x0644, 0x0645, 0x0646, 0x0647,
  0x0648, 0x0649, 0x064a, 0x064b, 0x064c, 0x064d, 0x064e, 0x064f,
  /* 0xf0 */
  0x0650, 0x0651, 0x0652, 0xfed7, 0xfedb, 0xfedf, 0xf8fc, 0xfef5,
  0xfef7, 0xfef9, 0xfefb, 0xfee3, 0xfee7, 0xfeec, 0xfee9, 0xfffd,
};

static int
cp1046_mbtowc (conv_t conv, ucs4_t *pwc, const unsigned char *s, int n)
{
  unsigned char c = *s;
  if (c < 0x80) {
    *pwc = (ucs4_t) c;
    return 1;
  }
  else {
    unsigned short wc = cp1046_2uni[c-0x80];
    if (wc != 0xfffd) {
      *pwc = (ucs4_t) wc;
      return 1;
    }
  }
  return RET_ILSEQ;
}

static const unsigned char cp1046_page00[112] = {
  0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x88-0x8f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x90-0x97 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x98-0x9f */
  0xa0, 0x00, 0x00, 0x00, 0xa4, 0x00, 0x00, 0x00, /* 0xa0-0xa7 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0xad, 0x00, 0x00, /* 0xa8-0xaf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xb0-0xb7 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xb8-0xbf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xc0-0xc7 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xc8-0xcf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, /* 0xd0-0xd7 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xd8-0xdf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xe0-0xe7 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xe8-0xef */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, /* 0xf0-0xf7 */
};
static const unsigned char cp1046_page06[104] = {
  0x00, 0x00, 0x00, 0x00, 0xac, 0x00, 0x00, 0x00, /* 0x08-0x0f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10-0x17 */
  0x00, 0x00, 0x00, 0xbb, 0x00, 0x00, 0x00, 0xbf, /* 0x18-0x1f */
  0x00, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, /* 0x20-0x27 */
  0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, /* 0x28-0x2f */
  0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, /* 0x30-0x37 */
  0x00, 0xd9, 0xda, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x38-0x3f */
  0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, /* 0x40-0x47 */
  0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef, /* 0x48-0x4f */
  0xf0, 0xf1, 0xf2, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x50-0x57 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x58-0x5f */
  0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, /* 0x60-0x67 */
  0xb8, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x68-0x6f */
};
static const unsigned char cp1046_page25[32] = {
  0x8b, 0x00, 0x8a, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x00-0x07 */
  0x00, 0x00, 0x00, 0x00, 0x8d, 0x00, 0x00, 0x00, /* 0x08-0x0f */
  0x8c, 0x00, 0x00, 0x00, 0x8e, 0x00, 0x00, 0x00, /* 0x10-0x17 */
  0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x18-0x1f */
};
static const unsigned char cp1046_pagef8[16] = {
  0x00, 0x00, 0x00, 0x00, 0x85, 0x84, 0x83, 0x86, /* 0xf0-0xf7 */
  0xa3, 0xa2, 0xa1, 0xa5, 0xf6, 0x00, 0x00, 0x00, /* 0xf8-0xff */
};
static const unsigned char cp1046_pagefe[144] = {
  0x00, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94, /* 0x70-0x77 */
  0x00, 0x90, 0x00, 0x91, 0x00, 0x92, 0x00, 0x93, /* 0x78-0x7f */
  0x00, 0x00, 0xdc, 0x00, 0xdd, 0x00, 0x00, 0x00, /* 0x80-0x87 */
  0x80, 0x00, 0x95, 0xa6, 0x00, 0x00, 0xde, 0x00, /* 0x88-0x8f */
  0x00, 0xa7, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa8, /* 0x90-0x97 */
  0x00, 0x00, 0x00, 0xa9, 0x00, 0x00, 0x00, 0xaa, /* 0x98-0x9f */
  0x00, 0x00, 0x00, 0xab, 0x00, 0x00, 0x00, 0xae, /* 0xa0-0xa7 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xa8-0xaf */
  0x00, 0x00, 0x00, 0xaf, 0x00, 0x00, 0x00, 0xba, /* 0xb0-0xb7 */
  0x00, 0x00, 0x00, 0xbc, 0x00, 0x00, 0x00, 0xbd, /* 0xb8-0xbf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd8, /* 0xc0-0xc7 */
  0x00, 0x00, 0xbe, 0xc0, 0xdb, 0x00, 0x99, 0x9a, /* 0xc8-0xcf */
  0x9b, 0x00, 0x00, 0xdf, 0x00, 0x00, 0x00, 0xf3, /* 0xd0-0xd7 */
  0x00, 0x00, 0x00, 0xf4, 0x00, 0x00, 0x00, 0xf5, /* 0xd8-0xdf */
  0x00, 0x00, 0x00, 0xfb, 0x00, 0x00, 0x00, 0xfc, /* 0xe0-0xe7 */
  0x00, 0xfe, 0x00, 0x00, 0xfd, 0x00, 0x00, 0x00, /* 0xe8-0xef */
  0x96, 0x00, 0x98, 0x97, 0x00, 0xf7, 0x9c, 0xf8, /* 0xf0-0xf7 */
  0x9d, 0xf9, 0x9e, 0xfa, 0x9f, 0x00, 0x00, 0x00, /* 0xf8-0xff */
};

static int
cp1046_wctomb (conv_t conv, unsigned char *r, ucs4_t wc, int n)
{
  unsigned char c = 0;
  if (wc < 0x0080) {
    *r = wc;
    return 1;
  }
  else if (wc >= 0x0088 && wc < 0x00f8)
    c = cp1046_page00[wc-0x0088];
  else if (wc >= 0x0608 && wc < 0x0670)
    c = cp1046_page06[wc-0x0608];
  else if (wc >= 0x2500 && wc < 0x2520)
    c = cp1046_page25[wc-0x2500];
  else if (wc == 0x25a0)
    c = 0x89;
  else if (wc >= 0xf8f0 && wc < 0xf900)
    c = cp1046_pagef8[wc-0xf8f0];
  else if (wc >= 0xfe70 && wc < 0xff00)
    c = cp1046_pagefe[wc-0xfe70];
  if (c != 0) {
    *r = c;
    return 1;
  }
  return RET_ILUNI;
}

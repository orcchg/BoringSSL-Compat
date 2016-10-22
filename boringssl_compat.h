/** 
 *   HTTP Chat server with authentication and multi-channeling.
 *
 *   Copyright (C) 2016  Maxim Alov
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software Foundation,
 *   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 *   This program and text files composing it, and/or compiled binary files
 *   (object files, shared objects, binary executables) obtained from text
 *   files of this program using compiler, as well as other files (text, images, etc.)
 *   composing this program as a software project, or any part of it,
 *   cannot be used by 3rd-parties in any commercial way (selling for money or for free,
 *   advertising, commercial distribution, promotion, marketing, publishing in media, etc.).
 *   Only the original author - Maxim Alov - has right to do any of the above actions.
 */

#ifndef BORINGSSL_COMPAT__H__
#define BORINGSSL_COMPAT__H__

#if USE_BORINGSSL

#include "boringssl/include/openssl/aes.h"
#include "boringssl/include/openssl/conf.h"
#include "boringssl/include/openssl/err.h"
#include "boringssl/include/openssl/evp.h"
#include "boringssl/include/openssl/pem.h"
#include "boringssl/include/openssl/rand.h"
#include "boringssl/include/openssl/rsa.h"
#include "boringssl/include/openssl/sha.h"
#include "boringssl/include/openssl/cipher.h"
#include "boringssl/include/openssl/mem.h"
#include "boringssl/include/openssl/objects.h"
#include "boringssl/include/openssl/x509.h"

int EVP_SealInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *type, unsigned char **ek,
	     int *ekl, unsigned char *iv, EVP_PKEY **pubk, int npubk);

int EVP_SealUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl, unsigned char *in, int inl);

int EVP_SealFinal(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl);

int EVP_OpenInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *type,
	const unsigned char *ek, int ekl, const unsigned char *iv,
	EVP_PKEY *priv);

int EVP_OpenUpdate(EVP_CIPHER_CTX *ctx, uint8_t *out, int *out_len,
                      const uint8_t *in, int in_len);

int EVP_OpenFinal(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl);

#else

#include <openssl/aes.h>
#include <openssl/conf.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/rand.h>
#include <openssl/rsa.h>
#include <openssl/sha.h>
#include <openssl/objects.h>
#include <openssl/x509.h>

#endif  // USE_BORINGSSL

#endif  // BORINGSSL_COMPAT__H__


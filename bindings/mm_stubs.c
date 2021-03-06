/*
 * Copyright (c) 2015 Thomas Leonard <talex5@gmail.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <mini-os/mm.h>

CAMLprim value
stub_heap_get_pages_total(value unit) // noalloc
{
  return Val_long(minios_heap_pages_total);
}

CAMLprim value
stub_heap_get_pages_used(value unit) // noalloc
{
  return Val_long(minios_heap_pages_used);
}

/* expose the virt_to_mfn macro for converting a
   virtual page number to a machine frame number
*/
CAMLprim value
stub_virt_to_mfn(value page)
{
  CAMLparam1(page);
  CAMLlocal1(result);
  result = caml_copy_nativeint(virt_to_mfn(Nativeint_val(page)));
  CAMLreturn(result);
}

/* -*- c++ -*- */

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/fail.h>
#include <caml/callback.h>

#include <thread>

extern "C" {

  CAMLprim value
  core_count_ml(__attribute__((unused)) value)
  {
    CAMLparam0();
    unsigned int n = std::thread::hardware_concurrency();
    if (n == 0) {
      caml_raise_constant(*caml_named_value("count_not_defined_exn"));
    } else {
      CAMLreturn(caml_copy_nativeint(n));
    }
  }

}

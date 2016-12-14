(** Get a count of cores on the current machine, simple exposure of
    http://en.cppreference.com/w/cpp/thread/thread/hardware_concurrency *)

(** Raised when the value is not well defined or not computable*)
exception Count_not_defined

let () =
  Callback.register_exception
    "count_not_defined_exn"
    Count_not_defined

(** Returns the number of cores on the current machine*)
external count : unit -> Nativeint.t = "core_count_ml"

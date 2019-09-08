let () =
  (Corecount.count () |> Nativeint.to_int)
  |> Printf.sprintf "Count %d"
  |> print_endline

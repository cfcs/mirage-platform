module Heap_pages = struct
  external total: unit -> int = "stub_heap_get_pages_total" "noalloc"
  external used: unit -> int = "stub_heap_get_pages_used" "noalloc"
end

external virt_to_mfn: nativeint -> nativeint = "stub_virt_to_mfn"

NTSTATUS KeAddTriageDumpDataBlock(
  [_Inout_] PKTRIAGE_DUMP_DATA_ARRAY KtriageDumpDataArray,
            PVOID                    Address,
  [_In_]    SIZE_T                   Size
);
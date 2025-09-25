typedef struct _NET_BUFFER_DATA {
  NET_BUFFER             *Next;
  MDL                    *CurrentMdl;
  ULONG                  CurrentMdlOffset;
  NET_BUFFER_DATA_LENGTH NbDataLength;
  MDL                    *MdlChain;
  ULONG                  DataOffset;
} NET_BUFFER_DATA, *PNET_BUFFER_DATA;
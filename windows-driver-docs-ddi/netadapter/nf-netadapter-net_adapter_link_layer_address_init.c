void NET_ADAPTER_LINK_LAYER_ADDRESS_INIT(
  [_Out_]                    NET_ADAPTER_LINK_LAYER_ADDRESS *LinkLayerAddress,
  [_In_range_(1,32)]         USHORT                         Length,
  [_In_reads_bytes_(Length)] UCHAR const                    *AddressBuffer
);
void NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES_INIT(
  [_Out_] NET_ADAPTER_RECEIVE_SCALING_CAPABILITIES                *Capabilities,
  [_In_]  SIZE_T                                                  NumberOfQueues,
  [_In_]  NET_ADAPTER_RECEIVE_SCALING_UNHASHED_TARGET_TYPE        UnhashedTargetType,
  [_In_]  NET_ADAPTER_RECEIVE_SCALING_HASH_TYPE                   HashTypes,
  [_In_]  NET_ADAPTER_RECEIVE_SCALING_PROTOCOL_TYPE               ProtocolTypes,
  [_In_]  PFN_NET_ADAPTER_RECEIVE_SCALING_ENABLE                  Enable,
  [_In_]  PFN_NET_ADAPTER_RECEIVE_SCALING_DISABLE                 Disable,
  [_In_]  PFN_NET_ADAPTER_RECEIVE_SCALING_SET_HASH_SECRET_KEY     SetHashSecretKey,
  [_In_]  PFN_NET_ADAPTER_RECEIVE_SCALING_SET_INDIRECTION_ENTRIES SetIndirectionEntries
);
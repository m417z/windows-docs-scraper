NTSTATUS NetAdapterCreate(
  [_In_]     NETADAPTER_INIT       *AdapterInit,
  [_In_opt_] WDF_OBJECT_ATTRIBUTES *AdapterAttributes,
  [_Out_]    NETADAPTER            *Adapter
);
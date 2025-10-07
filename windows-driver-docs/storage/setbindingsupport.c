void SetBindingSupport(
   [in, HBAType("HBA_WWN")] uint8               PortWWN[8],
   [in, HBA_BIND_TYPE_QUALIFIERS] HBA_BIND_TYPE BindType,
   [out, HBA_STATUS_QUALIFIERS ] HBA_STATUS     HBAStatus
);
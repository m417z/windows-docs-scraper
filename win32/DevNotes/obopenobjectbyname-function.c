NTSTATUS
ObOpenObjectByName (
    __in POBJECT_ATTRIBUTES ObjectAttributes,
    __in POBJECT_TYPE ObjectType,
    __in KPROCESSOR_MODE AccessMode,
    __inout_opt PACCESS_STATE AccessState,
    __in_opt ACCESS_MASK DesiredAccess,
    __inout_opt PVOID ParseContext,
    __out PHANDLE Handle
    )
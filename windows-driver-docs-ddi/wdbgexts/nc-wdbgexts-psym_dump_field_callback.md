# PSYM_DUMP_FIELD_CALLBACK callback

## Description

The PSYM_DUMP_FIELD_CALLBACK callback function is called by the debugger engine during the [IG_DUMP_SYMBOL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_sym_dump_param) Ioctl operation with information about a member in the specified symbol.

## Parameters

### `pField`

Specifies the field for which this callback function is being called. The debugger engine fills in the contents of this parameter before making the call. See [FIELD_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_field_info) for details about the members of this parameter.

### `UserContext`

Specifies the user context object passed to the **Ioctl** operation in the **Context** member of the SYM_DUMP_PARAM structure.

## Return value

If the function is successful, it should return STATUS_SUCCESS. Otherwise, it should return an appropriate error code.

## Remarks

If you are writing a WdbgExts extension, include wdbgexts.h. If you are writing a DbgEng extension that uses this function prototype, include wdbgexts.h before dbgeng.h (see [Writing DbgEng Extension Code](https://learn.microsoft.com/windows-hardware/drivers/debugger/writing-dbgeng-extension-code) for details). STATUS_SUCCESS and other status and error codes are defined in ntstatus.h.

## See also

[FIELD_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_field_info)

[IG_DUMP_SYMBOL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_sym_dump_param)

[Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine)
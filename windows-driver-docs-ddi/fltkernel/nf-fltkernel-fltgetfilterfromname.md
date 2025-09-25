# FltGetFilterFromName function

## Description

The **FltGetFilterFromName** routine returns an opaque filter pointer for a registered minifilter driver whose name matches the value in the *FilterName* parameter.

## Parameters

### `FilterName` [in]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure containing the minifilter driver name. (The name comparison is case-insensitive.)

### `RetFilter` [out]

Pointer to a caller-allocated variable that receives an opaque filter pointer for the minifilter driver whose name matches the name in the *FilterName* parameter. This parameter is required and cannot be **NULL**.

## Return value

**FltGetFilterFromName** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DELETING_OBJECT** | A matching minifilter driver was found, but it is being torn down. This is an error code. |
| **STATUS_FLT_FILTER_NOT_FOUND** | No matching minifilter driver was found. This is an error code. |

## Remarks

**FltGetFilterFromName** adds a rundown reference to the opaque filter pointer returned in the *RetFilter* parameter. When this pointer is no longer needed, the caller must release it by calling [FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference). Thus every successful call to **FltGetFilterFromName** must be matched by a subsequent call to **FltObjectDereference**.

To register a minifilter driver with the Filter Manager, call [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter).

## See also

[FltObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltobjectdereference)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)
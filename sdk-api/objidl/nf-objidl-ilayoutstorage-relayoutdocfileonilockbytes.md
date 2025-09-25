# ILayoutStorage::ReLayoutDocfileOnILockBytes

## Description

Not supported.

The **ReLayoutDocfileOnILockBytes** method is not implemented. If called, it returns **STG_E_UNIMPLEMENTEDFUNCTION**.

## Parameters

### `pILockBytes` [in]

A pointer to the [ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) interface on the underlying byte-array object where the compound file is to be rewritten.

## Return value

This method returns the following value.

| Return code | Description |
| --- | --- |
| **STG_E_UNIMPLEMENTEDFUNCTION** | This method is not implemented. |

## Remarks

If implemented, it would rewrite the compound file in the byte-array object specified by the caller. It would return **S_OK** for success or one of the **STG_E_*** error codes for failure.
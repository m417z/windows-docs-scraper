# ILog::SetAccessPolicyHint

## Description

Provides a hint to the implementation about the pattern in which records will be read.

## Parameters

### `policy` [in]

The pattern in which records will most often be read. For more information, see the [RECORD_READING_POLICY](https://learn.microsoft.com/windows/desktop/api/txlogpub/ne-txlogpub-record_reading_policy) enumeration.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Not all implementations of [ILog](https://learn.microsoft.com/windows/desktop/api/txlogpub/nn-txlogpub-ilog) will be optimized for reading records in a particular pattern. An implementation may choose to ignore this request and return S_OK.

## See also

[ILog](https://learn.microsoft.com/windows/desktop/api/txlogpub/nn-txlogpub-ilog)

[RECORD_READING_POLICY](https://learn.microsoft.com/windows/desktop/api/txlogpub/ne-txlogpub-record_reading_policy)
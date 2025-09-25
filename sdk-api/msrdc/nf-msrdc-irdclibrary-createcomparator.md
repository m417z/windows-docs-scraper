# IRdcLibrary::CreateComparator

## Description

The **CreateComparator** method
creates a signature comparator.

## Parameters

### `iSeedSignaturesFile` [in]

An [IRdcFileReader](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcfilereader) interface pointer initialized to
read the seed signatures.

### `comparatorBufferSize` [in]

Specifies the size of the comparator buffer. The range is from
**MSRDC_MINIMUM_COMPAREBUFFER** to
**MSRDC_MAXIMUM_COMPAREBUFFER**.

#### MSRDC_MINIMUM_COMPAREBUFFER (100000)

Minimum size of a comparator buffer.

#### MSRDC_DEFAULT_COMPAREBUFFER (3200000)

Default size of a comparator buffer. Used if zero (0) is passed for
*comparatorBufferSize*.

#### MSRDC_MAXIMUM_COMPAREBUFFER (1073741824)

Maximum size of a comparator buffer. (1<<30)

### `iComparator` [out]

Pointer to a location that will receive an
[IRdcComparator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdccomparator) interface pointer. On a successful return
the interface will be initialized on return. Callers must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The caller must create a separate signature comparator for each
level of recursion.

## See also

[IRdcComparator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdccomparator)

[IRdcFileReader](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcfilereader)

[IRdcLibrary](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdclibrary)
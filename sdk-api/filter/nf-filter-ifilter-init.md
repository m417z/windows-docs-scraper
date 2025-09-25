# IFilter::Init

## Description

Initializes a filtering session.

## Parameters

### `grfFlags` [in]

Values from the [IFILTER_INIT](https://learn.microsoft.com/windows/desktop/api/filter/ne-filter-ifilter_init) enumeration for controlling text standardization, property output, embedding scope, and [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) access patterns.

### `cAttributes` [in]

The size of the attributes array. When nonzero, *cAttributes* takes precedence over attributes specified in *grfFlags*. If no attribute flags are specified and *cAttributes* is zero, the default is given by the PSGUID_STORAGE storage property set, which contains the date and time of the last write to the file, size, and so on; and by the PID_STG_CONTENTS 'contents' property, which maps to the main contents of the file. For more information about properties and property sets, see [Property Sets](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/property-sets).

### `aAttributes` [in]

Pointer to an array of [FULLPROPSPEC](https://learn.microsoft.com/windows/desktop/api/filter/ns-filter-fullpropspec) structures for the requested properties. When *cAttributes* is nonzero, only the properties in *aAttributes* are returned.

### `pFlags` [out]

Information about additional properties available to the caller; from the [IFILTER_FLAGS](https://learn.microsoft.com/windows/desktop/api/filter/ne-filter-ifilter_flags) enumeration.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **E_FAIL** | File to filter was not previously loaded. |
| **E_INVALIDARG** | Count and contents of attributes do not agree. |
| **FILTER_E_PASSWORD** | Access has been denied because of password protection or similar security measures. |
| **FILTER_E_ACCESS** | General access failures |

## Remarks

The **Init** method sets the state of the filter object. The content filter positions at the beginning of the object and the object state is frozen until the object is released. You can pass the filter object the set of properties you would like returned by setting up their property set and property identifier (ID) descriptions in the *aAttributes* array. For more information, see [Filtering File Properties](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/filtering-file-properties).

### Notes to Callers

Call the **Init** method before calling all other [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) methods.

### Notes to Implementers

Chunk IDs must remain consistent across multiple calls to the **Init** method with the same parameters.

For some implementations of the [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) interface, detection of failure to access a document may not be possible (or may be computationally expensive) until the **Init** method has been called, or possibly even later.

## See also

[FULLPROPSPEC](https://learn.microsoft.com/windows/desktop/api/filter/ns-filter-fullpropspec)

[IFILTER_FLAGS](https://learn.microsoft.com/windows/desktop/api/filter/ne-filter-ifilter_flags)

[IFILTER_INIT](https://learn.microsoft.com/windows/desktop/api/filter/ne-filter-ifilter_init)

[IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter)
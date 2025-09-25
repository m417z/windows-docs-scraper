# IDataAdviseHolder::SendOnDataChange

## Description

Sends notifications to each advise sink for which there is a connection established by calling the [IAdviseSink::OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange) method for each advise sink currently being handled by this instance of the advise holder object.

## Parameters

### `pDataObject` [in]

A pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface on the data object in which the data has just changed. This pointer is used in subsequent calls to [IAdviseSink::OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange).

### `dwReserved` [in]

This parameter is reserved and must be 0.

### `advf` [in]

Container for advise flags that specify how the call to [IAdviseSink::OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange) is made. These flag values are from the enumeration [ADVF](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-advf). Typically, the value for *advf* is **NULL**. The only exception occurs when the data object is shutting down and must send a final notification that includes the actual data to sinks that have specified ADVF_DATAONSTOP and ADVF_NODATA in their call to [IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise). In this case, *advf* contains ADVF_DATAONSTOP.

## Return value

This method returns S_OK on success.

## Remarks

The data object must call this method when it detects a change that would be of interest to an advise sink that has previously requested notification.

Most notifications include the actual data with them. The only exception is if the ADVF_NODATA flag was previously specified when the connection was initially set up in the [IDataAdviseHolder::Advise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataadviseholder-advise) method.

Before calling the [IAdviseSink::OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange) method for each advise sink, this method obtains the actual data by calling the [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) method through the pointer specified in the *pDataObject* parameter.

## See also

[IAdviseSink::OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange)

[IDataAdviseHolder](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataadviseholder)
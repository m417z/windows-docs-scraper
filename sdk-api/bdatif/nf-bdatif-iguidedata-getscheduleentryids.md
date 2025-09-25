# IGuideData::GetScheduleEntryIDs

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetScheduleEntryIDs** method returns a list of unique identifiers for all of the schedule entries contained in all transport streams.

## Parameters

### `pEnumScheduleEntries` [out]

Receives a pointer to the **IEnumVARIANT** interface. Use this interface to enumerate the collection. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The method fails if the TIF has not received the schedule information from the PSI tables in the transport stream. The client should implement the [IGuideDataEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-iguidedataevent) interface and wait for the [IGuideDataEvent::ScheduleEntryChanged](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-iguidedataevent-scheduleentrychanged) event to be fired.

Each **VARIANT** type in the collection contains a **BSTR** that uniquely identifies one schedule entry within the multiplex. To get more information about the schedule entry, pass the **VARIANT** to the [IGuideData::GetScheduleEntryProperties](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-iguidedata-getscheduleentryproperties) method.

The returned **IEnumVARIANT** interface is not thread safe. Clients should not call methods on the interface from more than one thread.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGuideData Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-iguidedata)
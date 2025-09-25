# IGuideData::GetScheduleEntryProperties

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetScheduleEntryProperties** method retrieves the properties for a specified schedule entry.

## Parameters

### `varScheduleEntryDescriptionID` [in]

Specifies the unique identifier for the schedule entry. Call the [IGuideData::GetScheduleEntryIDs](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-iguidedata-getscheduleentryids) method to get a list of schedule entry identifiers.

### `ppEnumProperties` [out]

Pointer to a variable that receives an [IEnumGuideDataProperties](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-ienumguidedataproperties) interface pointer. Use this interface to enumerate the properties. The caller must release the interface

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The returned collection includes the following properties.

| Property | Description |
| --- | --- |
| Description.ID | The unique identifier for the schedule entry. |
| Time.Start | The starting time and date of this schedule entry. The value of this property is an unsigned `long` containing the time and date in GPS time. |
| Time.End | The ending time and date of this schedule entry. The value of this property is an unsigned `long` containing the time and date in GPS time. |
| ScheduleEntry.ProgramID | Identifies the program that will play at the time specified by this schedule entry. The value of this property corresponds to the Description.ID property of the program. |
| ScheduleEntry.ServiceID | Identifies the service that carries the program represented by this schedule entry. The value of this property corresponds to the Description.ID property of the service. |

The method fails if the TIF has not received the schedule information from the PSI tables in the transport stream. The client should implement the [IGuideDataEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-iguidedataevent) interface and wait for the [IGuideDataEvent::ScheduleEntryChanged](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-iguidedataevent-scheduleentrychanged) event to be fired.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGuideData Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-iguidedata)
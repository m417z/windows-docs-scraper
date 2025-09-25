# IGuideData::GetProgramProperties

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetProgramProperties** method retrieves the properties for a specified program.

## Parameters

### `varProgramDescriptionID` [in]

Specifies the unique identifier for the program. Call the [IGuideData::GetGuideProgramIDs](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-iguidedata-getguideprogramids) method to get a list of program identifiers.

### `ppEnumProperties` [out]

Pointer to a variable that receives an [IEnumGuideDataProperties](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-ienumguidedataproperties) interface pointer. Use this interface to enumerate the properties. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The returned collection includes the following properties.

| Property | Description |
| --- | --- |
| Description.ID | The unique identifier for the program. |
| Description.One Sentence | The description of the program. |
| Description.Title | The name of the program. |

The method fails if the TIF has not received the program information from the PSI tables in the transport stream. The client should implement the [IGuideDataEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-iguidedataevent) interface and wait for the [IGuideDataEvent::ProgramChanged](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-iguidedataevent-programchanged) event to be fired.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGuideData Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-iguidedata)
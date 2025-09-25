# IGuideDataEvent::ProgramChanged

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **ProgramChanged** method is called when information about one or more programs has changed.

## Parameters

### `varProgramDescriptionID` [in]

Specifies the unique identifier of the program that has changed. Call [IGuideData::GetProgramProperties](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nf-bdatif-iguidedata-getprogramproperties) to get information about the program. The value of this parameter may be an empty **VARIANT** type (VT_EMPTY); if so, examine all of the programs to determine which ones have changed.

## Return value

Return S_OK if successful, or an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGuideDataEvent Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdatif/nn-bdatif-iguidedataevent)
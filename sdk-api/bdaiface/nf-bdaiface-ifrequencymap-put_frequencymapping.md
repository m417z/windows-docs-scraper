# IFrequencyMap::put_FrequencyMapping

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_FrequencyMapping** method sets the frequency table.

## Parameters

### `ulCount` [in]

Specifies the size of the array given in *pList*.

### `pList` [in]

Address of an array of size *ulCount*, allocated by the caller. The array should contain a list of all the frequencies (in kHz) that are valid in the current country/region.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Applications can use this method to modify a frequency table or create new frequency tables. The changes are not stored by the Network Provider; the application must store the information itself and call **put_FrequencyMapping** each time the Network Provider is created.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFrequencyMap Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ifrequencymap)
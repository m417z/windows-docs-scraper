# IFrequencyMap::get_FrequencyMapping

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_FrequencyMapping** method returns the Network Provider filter's current frequency table.

## Parameters

### `ulCount` [out]

Pointer to a variable that receives the size of the frequency table.

### `ppulList` [out]

Pointer to a variable that receives the address of the frequency table. The frequency table is an array of size *pulCount*, allocated by the method. The caller must free the array by calling **CoTaskMemFree**.

## Return value

Each entry in the frequency table is a tuning frequency, in kilohertz (kHz).

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFrequencyMap Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ifrequencymap)
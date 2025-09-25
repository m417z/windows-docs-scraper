# IAudioFormatEnumerator::GetFormat

## Description

Gets the format with the specified index in the list. The formats are listed in order of importance. The most preferable format is first in the list.

## Parameters

### `index` [in]

The index of the item in the list to retrieve.

### `format` [out]

Pointer to a pointer to a **WAVEFORMATEX** structure describing a supported audio format.

## Return value

If the method succeeds, it returns S_OK.

## See also

[IAudioFormatEnumerator](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-iaudioformatenumerator)
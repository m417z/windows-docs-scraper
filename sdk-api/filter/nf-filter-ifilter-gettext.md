# IFilter::GetText

## Description

Retrieves text (text-type properties) from the current chunk, which must have a [CHUNKSTATE](https://learn.microsoft.com/windows/desktop/api/filter/ne-filter-chunkstate) enumeration value of CHUNK_TEXT.

## Parameters

### `pcwcBuffer` [in, out]

On entry, the size of *awcBuffer* array in wide/Unicode characters. On exit, the number of Unicode characters written to *awcBuffer*.

### `awcBuffer` [out]

Text retrieved from the current chunk. Do not terminate the buffer with a character. Use a null-terminated string. The null-terminated string should not exceed the size of the destination buffer.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **FILTER_E_NO_TEXT** | The **flags** member of the [STAT_CHUNK](https://learn.microsoft.com/windows/desktop/api/filter/ns-filter-stat_chunk) structure for the current chunk does not have a value of CHUNK_TEXT. |
| **FILTER_E_NO_MORE_TEXT** | All the text in the current chunk has been returned. Additional calls to the [GetText](https://learn.microsoft.com/windows/desktop/api/filter/nf-filter-ifilter-gettext) method should return this error until the [IFilter::GetChunk](https://learn.microsoft.com/windows/desktop/api/filter/nf-filter-ifilter-getchunk) method has been called successfully. |
| **FILTER_S_LAST_TEXT** | As an optimization, the last call that returns text can return FILTER_S_LAST_TEXT, indicating that the next call to the [GetText](https://learn.microsoft.com/windows/desktop/api/filter/nf-filter-ifilter-gettext) method will return FILTER_E_NO_MORE_TEXT. This optimization can save time by eliminating unnecessary calls to **GetText**. |

## Remarks

If the current chunk is too large for the *awcBuffer* array, more than one call to the **GetText** method can be required to retrieve all the text in the current chunk. Each call to the **GetText** method retrieves text that immediately follows the text from the last call to the **GetText** method. The last character from one call can be in the middle of a word, and the first character in the next call would continue that word. Search engines must handle this situation.

## See also

[CHUNKSTATE](https://learn.microsoft.com/windows/desktop/api/filter/ne-filter-chunkstate)

[IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter)
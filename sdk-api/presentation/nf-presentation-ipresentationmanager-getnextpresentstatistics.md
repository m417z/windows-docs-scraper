## Description

Gets the next present statistics item in the queue.

## Parameters

### `nextPresentStatistics`

Type: **[IPresentStatistics](https://learn.microsoft.com/windows/win32/api/presentation/nn-presentation-ipresentstatistics) \*\***

A pointer to the next present statistics item in the queue , or `nullptr` if the queue is empty.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

If the present statistics queue is empty, no error will be returned. Instead, `nullptr` will be returned in the out parameter.

## See also
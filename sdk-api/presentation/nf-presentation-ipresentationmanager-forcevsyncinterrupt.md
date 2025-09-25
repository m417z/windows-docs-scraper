## Description

Sets a value that indicates whether the GPU should always issue a VSync interrupt when a present is shown.

## Parameters

### `forceVsyncInterrupt`

Type: **[BOOLEAN](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

`TRUE` to always issue a VSync interrupt; otherwise, `FALSE`.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

In order to take advantage of systems with hardware flip queue support, presents can be handled completely by the GPU without CPU involvement. This has power-saving benefits, but also means that buffer available events, the present retiring fence, and present statistics may not update immediately when the present is shown, but instead may update quite a bit later when the GPU periodically updates the CPU regarding what it has done independently.

An application can allow certain presents it doesn't need immediate feedback about to participate in this behavior by explicitly controlling whether the GPU should issue a VSync interrupt when each is shown. If not, such presents will result in improved power efficiency, at the cost of delayed feedback.

By default, presents will always force a VSync interrupt. Applications can opt into allowing some presents to not force a VSync interrupt by calling this method. If a system does not offer hardware flip queue support, all presents will issue a VSync interrupt and update the CPU, regardless of this setting.

This parameter setting persists across presents.

## See also
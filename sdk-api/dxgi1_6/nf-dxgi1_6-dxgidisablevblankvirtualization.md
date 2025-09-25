## Description

Disables v-blank virtualization for the process. This virtualization is used by the dynamic refresh rate (DRR) feature by default for all swap chains to maintain a steady virtualized present rate and v-blank cadence from [IDXGIOutput::WaitForVBlank](https://learn.microsoft.com/windows/win32/api/dxgi/nf-dxgi-idxgioutput-waitforvblank). By disabling virtualization, these APIs will see the changing refresh rate.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns **S_OK** if successful; an error code otherwise. For a full list of error codes, see [**DXGI_ERROR**](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-error).

## Remarks

By default, a DXGI swap chain is unable to observe the changing refresh rate that's caused by the dynamic refresh rate (DRR) feature (see the blog post [Dynamic refresh rate—Get the best of both worlds](https://devblogs.microsoft.com/directx/dynamic-refresh-rate/)). Instead, a swap chain is virtualized to always see a fraction of the refresh rate—60Hz if the DRR mode is 120Hz. **DXGIDisableVBlankVirtualization** disables that virtualization for the entire process. Your application will then see v-blank timings change as the system boosts between 60Hz and 120Hz, and frames will arrive at the corresponding times for each rate, with present statistics reflecting those changes.

You should call **DXGIDisableVBlankVirtualization** once per process, before creating any swap chains or calling [IDXGIOutput::WaitForVBlank](https://learn.microsoft.com/windows/win32/api/dxgi/nf-dxgi-idxgioutput-waitforvblank). It can't be disabled for the lifetime of the process, so any changes in v-blank timing or statistics from DRR boosting will remain observable to the process.

You can find more information on how Dynamic Refresh Rate works in the [Compositor clock](https://learn.microsoft.com/windows/win32/directcomp/compositor-clock/compositor-clock) topic.

## See also

* [Dynamic refresh rate—Get the best of both worlds](https://devblogs.microsoft.com/directx/dynamic-refresh-rate/)
* [Compositor clock](https://learn.microsoft.com/windows/win32/directcomp/compositor-clock/compositor-clock)
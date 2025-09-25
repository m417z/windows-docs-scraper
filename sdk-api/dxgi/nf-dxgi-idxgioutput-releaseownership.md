# IDXGIOutput::ReleaseOwnership

## Description

Releases ownership of the output.

## Remarks

If you are not using a swap chain, get access to an output by calling [IDXGIOutput::TakeOwnership](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgioutput-takeownership) and release it when you are finished by calling **IDXGIOutput::ReleaseOwnership**. An application that uses a swap chain will typically not call either of these methods.

## See also

[IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput)
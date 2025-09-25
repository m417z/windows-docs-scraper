# QueryAuxiliaryCounterFrequency function

## Description

Queries the auxiliary counter frequency.

## Parameters

### `lpAuxiliaryCounterFrequency` [out]

Long pointer to an output buffer that contains the specified auxiliary counter frequency. If the auxiliary counter is not supported, the value in the output buffer will be undefined.

## Return value

Returns **S_OK** if the auxiliary counter is supported and **E_NOTIMPL** if the auxiliary counter is not supported.

## Remarks

You can determine the availability of the auxiliary counter by comparing the returned value against **E_NOTIMPL**.

#### Examples

The following sample describes how to call **QueryAuxiliaryCounterFrequency** to retrieve the counter frequency.

```cpp
#include <stdio.h>
#include <windows.h>
int
wmain (int argc, wchar_t* argv[])
{

   ULONGLONG AuxiliaryCounterFrequency;
   HRESULT Result;

   Result = QueryAuxiliaryCounterFrequency(&AuxiliaryCounterFrequency);
   if (SUCCEEDED(Result)) {
      wprintf(L"Auxiliary counter frequency is: %llu.\n", AuxiliaryCounterFrequency);
   }
   else if (Result == E_NOTIMPL) {
      wprintf(L"Auxiliary counter is not supported.\n");
   }
	  else {
    wprintf(L"Error code: 0x%x.\n", Result);
   }

   return 0;
}

```
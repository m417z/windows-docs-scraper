# GetIntegratedDisplaySize function

## Description

Retrieves the best estimate of the diagonal size of the built-in screen, in inches.

## Parameters

### `sizeInInches` [out]

The best estimate of the diagonal size of the built-in screen, in inches.

## Return value

The result code indicating if the function succeeded or failed.

## Remarks

Uses the display driver as the source for display size information. Registry overrides to screen size will not be used. Uses the display adapter connection type to determine which display, if any, is integral to the system. If no internal display detected, an error will be returned. This requires the display to be active to be detected. For example, the lid cannot be closed when the function is called.

To compile an application that uses this function, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

The following function displays the best estimate of the diagonal size of the built-in screen, in inches.

```cpp
void ShowIntegratedDisplaySize()
{
  Platform::String^ buffer;

  double sizeInInches;
  HRESULT result = GetIntegratedDisplaySize(&sizeInInches) ;

  if (SUCCEEDED(result))
  {
    buffer += "Internal display size is " + sizeInInches.ToString() + " inches.\n";
  }
  else
  {
    buffer += "No valid Internal display found. \n";
  }

  // Output the string buffer here...
}

```

## See also

[System
Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)
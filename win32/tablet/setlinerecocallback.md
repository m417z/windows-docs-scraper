# SetLineRecoCallback function

Sets a callback function to be used during line recognition.

This helper function is not intended to be used by application code.

## Parameters

*hDivider* \[in\]

A handle to the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) object.

*pfn*

A pointer to a function that is called when recognition occurs on the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) passed in.

## Return value

This function can return one of these values.

| Return code | Description |
|----------------------------------------------------------------------------------------------|-------------------------------------------------|
| **S\_OK** | The function succeeded.<br> |
| **E\_INVALIDARG** | The *pDivider* parameter is invalid.<br> |

## Remarks

The following is the syntax for the callback function.

``` syntax
public delegate void GetLineRecoDef(
        int cStrokes,
        [MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.I4, SizeParamIndex = 0)]int [] aStrokeIds,
        float degrees,
        Point point,
        [MarshalAs(UnmanagedType.BStr)] out string lineString,
        out int cSegment,
        out int[] strokeIdOrdered,
        out int[] segmentStrokes,
        [MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.BStr)] out string [] aSegmentString
    );
```

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP Tablet PC Edition \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| Library<br> | InkDiv.dll |


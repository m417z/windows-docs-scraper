# IWDTFActions2::get__NewEnum

## Description

Gets a new iteration variable that the **For Each** loop structure implicitly uses.

## Parameters

### `ppNewEnum` [out]

The iteration variable.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You cannot access the **_NewEnum** property from the JScript programming language.

You must use the Active Template Library (ATL) to implement this functionality. For more information about how ATL implements this functionality, see the **ICollectionOnSTLImpl** interface in the MSDN Library.
# ITsSbProvider::CreateTargetObject

## Description

Creates an [ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget) target object.

## Parameters

### `TargetName` [in]

A **BSTR** variable that contains the target name.

### `EnvironmentName`

A **BSTR** variable that contains the environment name.

### `ppTarget` [out]

A pointer to a pointer to the specified target object. When you have finished using the object, release it by calling the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This method can return one of these values.

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list.

## Remarks

Plug-ins can use this method to create a target object.

## See also

[ITsSbProvider](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovider)

[ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget)
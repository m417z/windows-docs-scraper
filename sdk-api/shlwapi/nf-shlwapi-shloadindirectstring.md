# SHLoadIndirectString function

## Description

Extracts a specified text resource when given that resource in the form of an indirect string (a string that begins with the '@' symbol).

## Parameters

### `pszSource` [in]

Type: **PCWSTR**

A pointer to a buffer that contains the indirect string from which the resource will be retrieved. This string should begin with the '@' symbol and use one of the forms discussed in the Remarks section. This function will successfully accept a string that does not begin with an '@' symbol, but the string will be simply passed unchanged to *pszOutBuf*.

### `pszOutBuf` [out]

Type: **PWSTR**

A pointer to a buffer that, when this function returns successfully, receives the text resource. Both *pszOutBuf* and *pszSource* can point to the same buffer, in which case the original string will be overwritten.

### `cchOutBuf` [in]

Type: **UINT**

The size of the buffer pointed to by *pszOutBuf*, in characters.

### `ppvReserved`

Type: **void****

Not used; set to **NULL**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An indirect string can be provided in several forms, each of which has its own interpretation:

* **File name and resource ID**
  ``` syntax
  @filename,resource
  ```

  The string is extracted from the file named, using the *resource* value as a locator. If the resource value is zero or greater, the number becomes the index of the string in the binary file. If the number is negative, it becomes a resource ID. The retrieved string is copied to the output buffer and the function returns S_OK.
* **File name and resource ID with a version modifier**
  ``` syntax
  @filename,resource;v2
  ```

  This form can be used when a resource is changed but still uses the same index or ID as the old resource. Without a version modifier, the Multilingual User Interface (MUI) cache will not recognize that the resource has changed and will not refresh. By appending the version modifier, the value is seen as a new resource and is added to the cache. Note that it is recommended that you use a new ID or index for a new resource, and use a version modifier only when that is not possible.
* **PRI file path and resource ID**
  ``` syntax
  @{PRIFilepath?resource}
  ```

  The Package Resource Index (PRI) is a binary format introduced in Windows 8 that contains indexed resources or references to resources. The .pri file is bundled as part of an app's package. For more information on .pri files, see [Creating and retrieving resources in Windows Store apps](https://learn.microsoft.com/previous-versions/hh694557(v=vs.110)).

  The string is extracted from the .pri file named, using the *resource* as a locator. The retrieved string is copied to the output buffer and the function returns S_OK. The string is extracted based on the current Shell environment or [ResourceContext](https://learn.microsoft.com/uwp/api/windows.applicationmodel.resources.core.resourcecontext).

  An example of this type of indirect string is shown here.

  ```

  @{C:\Program Files\WindowsApps\Microsoft.Camera_6.2.8376.0_x64__8wekyb3d8bbwe\resources.pri? ms-resource://Microsoft.Camera/resources/manifestAppDescription}
  ```
* **Package name and resource ID**
  ``` syntax
  @{PackageFullName?resource}
  ```

  The string is extracted from the Resources.pri file stored in the app's root directory of the package identified by *PackageFullName*, using the *resource* as a locator. The retrieved string is copied to the output buffer and the function returns S_OK. The string is extracted based on the app's environment or [ResourceContext](https://learn.microsoft.com/uwp/api/windows.applicationmodel.resources.core.resourcecontext).

  **Note** This string must refer to a package installed for the current user. If it does not, the call will fail.

  An example of this type of indirect string is shown here. In this example, the reference name is fully-qualified, but it contains no namespace (for example, "resources"). The deployment stack expands the name to look for it in all namespaces.

  ```

  @{Microsoft.Camera_6.2.8376.0_x64__8wekyb3d8bbwe? ms-resource://Microsoft.Camera/manifestAppDescription}
  ```

  In this next example, the fully-qualified reference name does specify a namespace to limit the lookup to.

  ```

  @{Microsoft.Camera_6.2.8376.0_x64__8wekyb3d8bbwe? ms-resource://Microsoft.Camera/resources/manifestAppDescription}
  ```

If the string is not an indirect string, then the string is directly copied without change to *pszOutBuf* and the function returns S_OK.
# ASSOCSTR enumeration

## Description

Used by [IQueryAssociations::GetString](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-iqueryassociations-getstring) to define the type of string that is to be returned.

## Constants

### `ASSOCSTR_COMMAND:1`

A command string associated with a Shell verb.

### `ASSOCSTR_EXECUTABLE`

An executable from a Shell verb command string. For example, this string is found as the (Default) value for a subkey such as
**HKEY_CLASSES_ROOT**\*ApplicationName*\**shell**\**Open**\**command**. If the command uses Rundll.exe, set the **ASSOCF_REMAPRUNDLL** flag in the *flags* parameter of [IQueryAssociations::GetString](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-iqueryassociations-getstring) to retrieve the target executable.

**Caution**

Not all app associations have executables. Do not assume that an executable will always be present.

This type of string will identify the code that will be invoked in the implementation of the verb.

### `ASSOCSTR_FRIENDLYDOCNAME`

The friendly name of a document type.

### `ASSOCSTR_FRIENDLYAPPNAME`

The friendly name of an executable file.

### `ASSOCSTR_NOOPEN`

Ignore the information associated with the **open** subkey.

### `ASSOCSTR_SHELLNEWVALUE`

Look under the **ShellNew** subkey.

### `ASSOCSTR_DDECOMMAND`

A template for DDE commands.

### `ASSOCSTR_DDEIFEXEC`

The DDE command to use to create a process.

### `ASSOCSTR_DDEAPPLICATION`

The application name in a DDE broadcast.

### `ASSOCSTR_DDETOPIC`

The topic name in a DDE broadcast.

### `ASSOCSTR_INFOTIP`

Corresponds to the InfoTip registry value. Returns an info tip for an item, or list of properties in the form of an [IPropertyDescriptionList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionlist) from which to create an info tip, such as when hovering the cursor over a file name. The list of properties can be parsed with [PSGetPropertyDescriptionListFromString](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertydescriptionlistfromstring).

### `ASSOCSTR_QUICKTIP`

**Introduced in Internet Explorer 6**. Corresponds to the QuickTip registry value. Same as ASSOCSTR_INFOTIP, except that it always returns a list of property names in the form of an [IPropertyDescriptionList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionlist). The difference between this value and ASSOCSTR_INFOTIP is that this returns properties that are safe for any scenario that causes slow property retrieval, such as offline or slow networks. Some of the properties returned from ASSOCSTR_INFOTIP might not be appropriate for slow property retrieval scenarios. The list of properties can be parsed with [PSGetPropertyDescriptionListFromString](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertydescriptionlistfromstring).

### `ASSOCSTR_TILEINFO`

**Introduced in Internet Explorer 6**. Corresponds to the TileInfo registry value. Contains a list of properties to be displayed for a particular file type in a Windows Explorer window that is in tile view. This is the same as ASSOCSTR_INFOTIP, but, like ASSOCSTR_QUICKTIP, it also returns a list of property names in the form of an [IPropertyDescriptionList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionlist). The list of properties can be parsed with [PSGetPropertyDescriptionListFromString](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertydescriptionlistfromstring).

### `ASSOCSTR_CONTENTTYPE`

**Introduced in Internet Explorer 6**. Describes a general type of MIME file association, such as image and bmp, so that applications can make general assumptions about a specific file type.

### `ASSOCSTR_DEFAULTICON`

**Introduced in Internet Explorer 6**. Returns the path to the icon resources to use by default for this association. Positive numbers indicate an index into the dll's resource table, while negative numbers indicate a resource ID. An example of the syntax for the resource is "c:\myfolder\myfile.dll,-1".

### `ASSOCSTR_SHELLEXTENSION`

**Introduced in Internet Explorer 6**. For an object that has a Shell extension associated with it, you can use this to retrieve the CLSID of that Shell extension object by passing a string representation of the IID of the interface you want to retrieve as the *pwszExtra* parameter of [IQueryAssociations::GetString](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-iqueryassociations-getstring). For example, if you want to retrieve a handler that implements the [IExtractImage](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iextractimage) interface, you would specify "{BB2E617C-0920-11d1-9A0B-00C04FC2D6C1}", which is the IID of **IExtractImage**.

### `ASSOCSTR_DROPTARGET`

**Introduced in Internet Explorer 8**. For a verb invoked through COM and the [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) interface, you can use this flag to retrieve the **IDropTarget** object's CLSID. This CLSID is registered in the **DropTarget** subkey. The verb is specified in the *pwszExtra* parameter in the call to [IQueryAssociations::GetString](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-iqueryassociations-getstring).

This type of string will identify the code that will be invoked in the implementation of the verb.

### `ASSOCSTR_DELEGATEEXECUTE`

**Introduced in Internet Explorer 8**. For a verb invoked through COM and the [IExecuteCommand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iexecutecommand) interface, you can use this flag to retrieve the **IExecuteCommand** object's CLSID. This CLSID is registered in the verb's **command** subkey as the DelegateExecute entry. The verb is specified in the *pwszExtra* parameter in the call to [IQueryAssociations::GetString](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-iqueryassociations-getstring).

This type of string will identify the code that will be invoked in the implementation of the verb.

### `ASSOCSTR_SUPPORTED_URI_PROTOCOLS`

A string value of the URI protocol schemes. For example, `http:https:ftp:file:` or `*` indicating all.

### `ASSOCSTR_PROGID`

**Introduced in Windows 10**. The ProgID provided by the app associated with the file type or URI scheme. This if configured by users in their default program settings.

### `ASSOCSTR_APPID`

**Introduced in Windows 10**. The AppUserModelID of the app associated with the file type or URI scheme. This is configured by users in their default program settings.

### `ASSOCSTR_APPPUBLISHER`

**Introduced in Windows 10**. The publisher of the app associated with the file type or URI scheme. This is configured by users in their default program settings.

### `ASSOCSTR_APPICONREFERENCE`

**Introduced in Windows 10**. The icon reference of the app associated with the file type or URI scheme. This is configured by users in their default program settings.

### `ASSOCSTR_MAX`

The maximum defined ASSOCSTR value, used for validation purposes.
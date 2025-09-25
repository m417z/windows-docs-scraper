# IContextMenu::GetCommandString

## Description

Gets information about a shortcut menu command, including the help string and the language-independent, or *canonical*, name for the command.

## Parameters

### `idCmd`

Type: **UINT_PTR**

Menu command identifier offset.

### `uType`

Type: **UINT**

Flags specifying the information to return. This parameter can have one of the following values.

#### GCS_HELPTEXTA

Sets *pszName* to an ANSI string containing the help text for the command.

#### GCS_HELPTEXTW

Sets *pszName* to a Unicode string containing the help text for the command.

#### GCS_VALIDATEA

Returns S_OK if the menu item exists, or S_FALSE otherwise.

#### GCS_VALIDATEW

Returns S_OK if the menu item exists, or S_FALSE otherwise.

#### GCS_VERBA

Sets *pszName* to an ANSI string containing the language-independent command name for the menu item.

#### GCS_VERBW

Sets *pszName* to a Unicode string containing the language-independent command name for the menu item.

### `pReserved`

Type: **UINT***

Reserved. Applications must specify **NULL** when calling this method and handlers must ignore this parameter when called.

### `pszName`

Type: **LPSTR**

The address of the buffer to receive the null-terminated string being retrieved.

### `cchMax`

Type: **UINT**

Size of the buffer, in characters, to receive the null-terminated string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The language-independent command name, or *verb*, is a name that can be passed to the [IContextMenu::InvokeCommand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icontextmenu-invokecommand) method to activate a command by an application. The help text is a description of the command that Windows Explorer displays in its status bar. It should be reasonably short (under 40 characters).

Several common verbs can be identified by their canonical name, for instance, *open*, *print*, *delete*, and *rename*. Clients can compare the string pointed to by *pszName* against these canonical names to check for their presence on the shortcut menu.

Even though *pszName* is declared as an **LPSTR**, you must cast it to **UINT_PTR** and return a Unicode string if *uFlags* is set to either **GCS_HELPTEXTW** or **GCS_VERBW**. **GCS_UNICODE** can be used as a bitmask to test *uFlags* for 'W' and 'A' versions of the flag it contains.
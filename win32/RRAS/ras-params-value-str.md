# RAS\_PARAMS\_VALUE union

\[The **RAS\_PARAMS\_VALUE** union is not supported as of Windows Vista.\]

The **RAS\_PARAMS\_VALUE** union is used in the [**RAS\_PARAMETERS**](https://learn.microsoft.com/windows/win32/rras/ras-parameters-str) structure to store the data associated with a media-specific parameter. The **P\_Type** member of the **RAS\_PARAMETERS** structure uses a value from the [**RAS\_PARAMS\_FORMAT**](https://learn.microsoft.com/windows/win32/rras/ras-params-format-str) enumeration to indicate the type of value currently stored in **RAS\_PARAMS\_VALUE**.

## Members

**Number**

If the **P\_Type** member of the [**RAS\_PARAMETERS**](https://learn.microsoft.com/windows/win32/rras/ras-parameters-str) structure is ParamNumber, the **Number** member contains the value of the media-specific parameter. For example, the MAXCONNECTBPS parameter is of type ParamNumber, and the value might be 19200.

If the **P\_Type** member of the [**RAS\_PARAMETERS**](https://learn.microsoft.com/windows/win32/rras/ras-parameters-str) structure is ParamNumber, the **Number** member contains the value of the media-specific parameter. For example, the MAXCONNECTBPS parameter is of type ParamNumber, and the value might be 19200.

**String**

If the **P\_Type** member of the [**RAS\_PARAMETERS**](https://learn.microsoft.com/windows/win32/rras/ras-parameters-str) structure is ParamString, the **String** member contains the value of the media-specific parameter.

**Length**

Specifies the length, in characters, of the string pointed to by the **Data** member.

**Data**

Pointer to a buffer that contains the string value of a media-specific parameter.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| End of client support<br> | Windows XP<br> |
| End of server support<br> | Windows Server 2003<br> |
| Header<br> | Rassapi.h |

## See also

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/win32/rras/about-remote-access-service)

[RAS Server Administration Union](https://learn.microsoft.com/windows/win32/rras/ras-server-administration-union)

[**RAS\_PARAMETERS**](https://learn.microsoft.com/windows/win32/rras/ras-parameters-str)

[**RAS\_PARAMS\_FORMAT**](https://learn.microsoft.com/windows/win32/rras/ras-params-format-str)


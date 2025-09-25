# _DEV_BROADCAST_USERDEFINED structure

## Description

Contains the user-defined event and optional data associated with the
[DBT_USERDEFINED](https://learn.microsoft.com/windows/desktop/DevIO/dbt-userdefined) device event.

## Members

### `dbud_dbh`

Information about the device affected by a
[WM_DEVICECHANGE](https://learn.microsoft.com/windows/desktop/DevIO/wm-devicechange) message as specified by the
[DEV_BROADCAST_HDR](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_hdr) structure. Because
**_DEV_BROADCAST_USERDEFINED** is variable length, the **dbch_size** member of the **dbud_dbh** structure must be the size in bytes of the entire structure, including the variable length portion.

### `dbud_szName`

A pointer to a case-sensitive, null-terminated string that names the message. The string must consist of the vendor name, a backslash, followed by arbitrary user-defined null-terminated text.

## Remarks

Because this structure contains variable length fields, use it as a template for creating a pointer to a user-defined structure. Note that the structure must not contain pointers. The following example shows such a user-defined structure.

```cpp
#define NAME_LENGTH 32
#define USER_LENGTH 50

typedef struct tagWIDGET_WARE_DEV_BROADCAST_USERDEFINED
{
    struct _DEV_BROADCAST_HDR DBHeader;
    char   szName[NAME_LENGTH];
    BYTE   UserDefined[USER_LENGTH];
} WIDGET_WARE_DEV_BROADCAST_USERDEFINED;
```

## See also

[DBT_USERDEFINED](https://learn.microsoft.com/windows/desktop/DevIO/dbt-userdefined)

[DEV_BROADCAST_HDR](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_hdr)

[WM_DEVICECHANGE](https://learn.microsoft.com/windows/desktop/DevIO/wm-devicechange)
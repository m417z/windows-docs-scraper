# JET_CONVERT Structure

_**Applies to:** Windows | Windows Server_

## JET_CONVERT Structure

The **JET_CONVERT** structure contains the name of an earlier ESE version DLL that is used for reading a databases that are created with that earlier version. In addition, other flags are provided to control the nature of the conversion.

**Windows Server 2003:** The feature in [JetCompact](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcompact-function) that performed a conversion was removed from the product in Windows Server 2003. It is only supported in Windows 2000 and Windows XP.

```cpp
    typedef struct tagCONVERT {
      tchar* SzOldDll;
      union {
        unsigned long fFlags;
        struct {
          unsigned long fSchemaChangesOnly  :1;
        };
      };
    } JET_CONVERT;
```

### Members

**SzOldDll**

The name, including path information, to the earlier version of the ESE DLL.

**fFlags**

Reserved for system use.

**fSchemaChangesOnly**

Reserved for system use.

### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista, Windows XP, or Windows 2000 Professional.

|
|

**Server**

|

Requires Windows Server 2008, Windows Server 2003, or Windows 2000 Server.

|
|

**Header**

|

Declared in Esent.h.

|
|

**Unicode**

|

Implemented as **JET_CONVERT_W** (Unicode) and **JET_CONVERT_A** (ANSI).

|

### See Also

[JetCompact](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcompact-function)
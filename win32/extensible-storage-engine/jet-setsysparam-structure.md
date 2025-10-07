# JET_SETSYSPARAM Structure

_**Applies to:** Windows | Windows Server_

## JET_SETSYSPARAM Structure

An array of **JET_SETSYSPARAM** structures indicate a specific set of global system parameters that are set as an argument when using the [JetEnableMultiInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenablemultiinstance-function) function.

**Windows XP:** This structure is introduced in Windows XP.

```cpp
    typedef struct {
      unsigned long paramid;
      JET_API_PTR lParam;
      const tchar* sz;
      JET_ERR err;
    } JET_SETSYSPARAM;
```

### Members

**paramid**

The ID of the system parameter that will be set.

See [Extensible Storage Engine System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters) for a complete list of system parameters and their properties.

**lParam**

The optional value to be set for the selected system parameter if that system parameter is of an integer type.

**sz**

The optional value to be set for the selected system parameter if that system parameter is of a string type.

**err**

The error resulting from the call to [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function) with the previously specified parameters.

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

Implemented as **JET_ SETSYSPARAM_W** (Unicode) and **JET_ SETSYSPARAM_A** (ANSI).

|

### See Also

[Extensible Storage Engine System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters)
[JET_API_PTR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-api-ptr)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JetEnableMultiInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenablemultiinstance-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
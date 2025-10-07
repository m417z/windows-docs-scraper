# JET_ERRINFOBASIC_W Structure

_**Applies to:** Windows | Windows Server_

## JET_ERRINFOBASIC_W Structure

The **JET_ERRINFOBASIC_W** structure defines the data that is returned from the [JetGetErrorInfo()](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgeterrorinfow-function) method when the JET_ErrorInfoSpecificErr InfoLevel is passed in.

Note: This documentation is based on a preliminary release of the Extensible Storage Engine. This information is subject to change.

```cpp
typedef struct {
    unsigned long cbStruct;
    JET_ERR errValue;
    JET_ERRCAT errcatMostSpecific;
    unsigned char rgCategoricalHierarchy[8];
    unsigned long lSourceLine;
    WCHAR rgszSourceFile[64];
} JET_ERRINFOBASIC_W;
```

### Members

**cbStruct**

The size of the structure, in bytes. It must be set to sizeof( JET_ERRINFOBASIC ).

**errValue**

The error value that was evaluated, as passed in for the *pvResult* argument to [JetGetErrorInfo()](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgeterrorinfow-function).

**errcatMostSpecific**

The lowest-level [JET_ERRCAT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-errcat) constant that is associated with the error; that is, the leaf-level category in the category hierarchy documented in [JET_ERRCAT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-errcat).

**rgCategoricalHierarchy\[8\]**

The hierarchy of error categories that is associated with the error. Position 0 is the highest level in the hierarchy of [JET_ERRCAT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-errcat), and the rest are subcategories until the most specific category is set, after which all categories are JET_errcatUnknown.

**lSourceLine**

Reserved.

**rgszSourceFile\[64\]**

Reserved.

### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows 8.

|
|

**Server**

|

Requires Windows 8 Server.

|
|

**Header**

|

Declared in Esent.h.

|
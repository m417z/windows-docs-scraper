# OPENCARDNAMEA structure

## Description

The **OPENCARDNAME** structure contains the information that the
[GetOpenCardName](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-getopencardnamea) function uses to initialize a smart card **Select Card** dialog box. Calling [SCardUIDlgSelectCard](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scarduidlgselectcarda) with [OPENCARDNAME_EX](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-opencardname_exa) is recommended over calling [GetOpenCardName](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-getopencardnamea) with **OPENCARDNAME**. **OPENCARDNAME** is provided for backward compatibility.

## Members

### `dwStructSize`

Specifies the length, in bytes, of the structure. This member must not be **NULL**.

### `hwndOwner`

The window that owns the dialog box. This member can be any valid window handle, or it can be **NULL** for desktop default.

### `hSCardContext`

The context used for communication with the [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) [resource manager](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). Call
[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext) to set the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) and
[SCardReleaseContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardreleasecontext) to release it. This member must not be **NULL**.

### `lpstrGroupNames`

A pointer to a buffer that contains null-terminated group name strings. The last string in the buffer must be terminated by two null characters. Each string is the name of a group of cards that is to be included in the search. If **lpstrGroupNames** is **NULL**, the default group ([Scard$DefaultReaders](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly)) is searched.

### `nMaxGroupNames`

The maximum number of bytes (ANSI version) or characters ([Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) version) in the **lpstrGroupNames** string.

### `lpstrCardNames`

A pointer to a buffer that contains null-terminated card name strings. The last string in the buffer must be terminated by two null characters. Each string is the name of a card that is to be located.

### `nMaxCardNames`

The maximum number of bytes (ANSI version) or characters ([Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) version) in the **lpstrCardNames** string.

### `rgguidInterfaces`

Reserved for future use. Set to **NULL**. An array of GUIDs that identify the interfaces required.

### `cguidInterfaces`

Reserved for futures use. Set to **NULL**. The number of interfaces in the **rgguidInterfaces** array.

### `lpstrRdr`

If the card is located, the **lpstrRdr** buffer contains the name of the reader that contains the located card. The buffer should be at least 256 characters long.

### `nMaxRdr`

The size, in bytes (ANSI version) or characters ([Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) version), of the buffer pointed to by **lpstrRdr**. If the buffer is too small to contain the reader information,
[GetOpenCardName](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-getopencardnamea) returns SCARD_E_NO_MEMORY and the required size of the buffer pointed to by **lpstrRdr**.

### `lpstrCard`

If the card is located, the **lpstrCard** buffer contains the name of the located card. The buffer should be at least 256 characters long.

### `nMaxCard`

The size, in bytes (ANSI version) or characters ([Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) version), of the buffer pointed to by **lpstrCard**. If the buffer is too small to contain the card information, [GetOpenCardName](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-getopencardnamea) returns SCARD_E_NO_MEMORY and the required size of the buffer in **nMaxCard**.

### `lpstrTitle`

 A pointer to a string to be placed in the title bar of the dialog box. If this member is **NULL**, the system uses the default title "Select Card:".

### `dwFlags`

A set of bit flags you can use to initialize the dialog box. When the dialog box returns, it sets these flags to indicate the input of the user. This member can be a combination of the following flags.

| Value | Meaning |
| --- | --- |
| **SC_DLG_MINIMAL_UI** | Displays the dialog box only if the card being searched for by the calling application is not located and available for use in a reader. This allows the card to be found, connected (either through the internal dialog box mechanism or the user callback functions), and returned to the calling application. |
| **SC_DLG_NO_UI** | Force no display of the **Select Card** [user interface](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) (UI), regardless of search outcome. |
| **SC_DLG_FORCE_UI** | Force display of the **Select Card** UI, regardless of the search outcome. |

### `pvUserData`

A void pointer to user data. This pointer is passed back to the caller on the Connect, Check, and Disconnect routines.

### `dwShareMode`

If **lpfnConnect** is not **NULL**, the **dwShareMode** and **dwPreferredProtocols** members are ignored.

If **lpfnConnect** is **NULL** and **dwShareMode** is nonzero, then an internal call is made to
[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta) that uses **dwShareMode** and **dwPreferredProtocols** as the *dwShareMode* and *dwPreferredProtocols* parameters. If the connect succeeds, **hCardHandle** is set to the handle returned by **hSCardConnect**.

If **lpfnConnect** is **NULL** and **dwShareMode** is zero, the dialog box returns **hCardHandle** as **NULL**.

### `dwPreferredProtocols`

Used for internal connection as described in **dwShareMode**.

### `dwActiveProtocol`

Returns the actual protocol in use when the dialog box makes a connection to a card.

### `lpfnConnect`

A pointer to the card connect routine of the caller. If the caller needs to perform additional processing to connect to the card, this function pointer is set to the connect function for the user. If the connect function is successful, the card is left connected and initialized, and the card handle is returned.

The prototype for the connect routine is as follows.

```cpp
Connect(
  hSCardContext, // the card context passed in the parameter block
  szReader,      // the name of the reader
  mszCards,      // multiple string that contains the
                 //    possible card names in the reader
  pvUserData     // pointer to user data passed in parameter block
);

```

### `lpfnCheck`

A pointer to the card verify routine of the caller. If no special card verification is required, this pointer is **NULL**.

If the card is rejected by the verify routine, **FALSE** is returned and the card is disconnected, as indicated by **lpfnDisconnect**.

If the card is accepted by the verify routine, **TRUE** is returned. When the user accepts the card, all other cards currently connected will be disconnected, as indicated by **lpfnDisconnect**, and this card will be returned as the located card. The located card will remain connected.

The prototype for the check routine is as follows.

```cpp
Check(
  hSCardContext, // the card context passed in the parameter block
  hCard,         // card handle
  pvUserData     // pointer to user data passed in the parameter block
);

```

### `lpfnDisconnect`

A pointer to the card disconnect routine of the caller.

The prototype for the disconnect routine is as follows.

```cpp
Disconnect(
  hSCardContext, // the card context passed in the parameter block
  hCard,         // card handle
  pvUserData     // pointer to user data passed in the parameter block
);

```

**Note** When using **lpfnConnect**, **lpfnCheck**, and **lpfnDisconnect**, all three callback procedures should be present. Using these callbacks allows further verification that the calling application has found the appropriate card. This is the best way to ensure the appropriate card is selected.

### `hCardHandle`

A handle of the connected card (either through an internal dialog box connect or an **lpfnConnect** callback).

## See also

[GetOpenCardName](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-getopencardnamea)

[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta)

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardReleaseContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardreleasecontext)

[SCardUIDlgSelectCard](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scarduidlgselectcarda)

## Remarks

> [!NOTE]
> The winscard.h header defines OPENCARDNAME as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
# OPENCARD_SEARCH_CRITERIAA structure

## Description

The **OPENCARD_SEARCH_CRITERIA** structure is used by the
[SCardUIDlgSelectCard](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scarduidlgselectcarda) function in order to recognize cards that meet the requirements set forth by the caller. You can, however, call **SCardUIDlgSelectCard** without using this structure.

## Members

### `dwStructSize`

The length, in bytes, of the structure. Must not be **NULL**.

### `lpstrGroupNames`

A pointer to a buffer containing null-terminated group name strings. The last string in the buffer must be terminated by two null characters. Each string is the name of a group of cards that is to be included in the search. If **lpstrGroupNames** is **NULL**, the default group ([Scard$DefaultReaders](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly)) is searched.

### `nMaxGroupNames`

The maximum number of bytes (ANSI version) or characters ([Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) version) in the **lpstrGroupNames** string.

### `rgguidInterfaces`

Reserved for future use. An array of GUIDs that identifies the interfaces required. Set this member to **NULL**.

### `cguidInterfaces`

Reserved for future use. The number of interfaces in the **rgguidInterfaces** array. Set this member to **NULL**.

### `lpstrCardNames`

A pointer to a buffer that contains null-terminated card name strings. The last string in the buffer must be terminated by two null characters. Each string is the name of a card that is to be located.

### `nMaxCardNames`

The maximum number of bytes (ANSI version) or characters (Unicode version) in the **lpstrGroupNames** string.

### `lpfnCheck`

A pointer to the caller's card verify routine. If no special card verification is required, this pointer is **NULL**. If the card is rejected by the verify routine, **FALSE** is returned, and the card will be disconnected. If the card is accepted by the verify routine, **TRUE** is returned.

The prototype for the check routine is as follows.

```cpp
Boolean Check(
  hSCardContext, // the card context passed in the parameter block
  hCard,         // card handle
  pvUserData     // pointer to user data passed in the parameter block
);

```

### `lpfnConnect`

A pointer to the caller's card connect routine. If the caller needs to perform additional processing to connect to the card, this function pointer is set to the user's connect function. If the connect function is successful, the card is left connected and initialized, and the card handle is returned.

The prototype for the connect routine is as follows.

```cpp
Connect(
  hSCardContext, // the card context passed in the parameter block
  szReader,      // the name of the reader
  mszCards,      // multiple string that contains
                 //    the possible card names in the reader
  pvUserData     // pointer to user data passed in parameter block
);

```

### `lpfnDisconnect`

A pointer to the caller's card disconnect routine.

The prototype for the disconnect routine is as follows.

```cpp
Disconnect(
  hSCardContext, // the card context passed in the parameter block
  hCard,         // card handle
  pvUserData     // pointer to user data passed in the parameter block
);

```

**Note** When you use **lpfnConnect**, **lpfnCheck**, and **lpfnDisconnect**, all three callback procedures should be present. Using these callbacks allows further verification that the calling application has found the appropriate card. This is the best way to ensure the appropriate card is selected. However, when using a value that is not **NULL** for **lpfnCheck**, either both **lpfnConnect** and **lpfnDisconnect** must not be **NULL** (and **pvUserData** should also be provided), or **dwShareMode** and **dwPreferredProtocols** must both be set.

### `pvUserData`

Void pointer to user data. This pointer is passed back to the caller on the Connect, Check, and Disconnect routines.

### `dwShareMode`

If **lpfnConnect** is not **NULL**, the **dwShareMode** and **dwPreferredProtocols** members are ignored. If **lpfnConnect** is **NULL** and **dwShareMode** is nonzero, an internal call is made to
[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta) that uses **dwShareMode** and **dwPreferredProtocols** as the parameter.

### `dwPreferredProtocols`

Used for internal connection as described in **dwShareMode**.

## See also

[OPENCARDNAME_EX](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-opencardname_exa)

[SCardUIDlgSelectCard](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scarduidlgselectcarda)

## Remarks

> [!NOTE]
> The winscard.h header defines OPENCARD_SEARCH_CRITERIA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
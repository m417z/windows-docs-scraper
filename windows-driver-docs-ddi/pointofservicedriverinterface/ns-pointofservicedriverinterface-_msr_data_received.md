# _MSR_DATA_RECEIVED structure

## Description

This structure contains the data read from a swiped magnetic stripe card.

## Members

### `CardType`

Type of card that was swiped.

### `Track1EncryptedDataLength`

The amount of encrypted track 1 data, in bytes, that is stored in **Track1EncryptedData[MSR_TRACK_SIZE].**

### `Track2EncryptedDataLength`

The amount of encrypted track 2 data, in bytes, that is stored in **Track2EncryptedData[MSR_TRACK_SIZE].**

### `Track3EncryptedDataLength`

The amount of encrypted track 3 data, in bytes, that is stored in **Track3EncryptedData[MSR_TRACK_SIZE].**

### `Track4EncryptedDataLength`

The amount of encrypted track 4 data, in bytes, that is stored in **Track4EncryptedData[MSR_TRACK_SIZE].**

### `Track1EncryptedData`

The encrypted data read from track 1 of the swiped card.

### `Track2EncryptedData`

The encrypted data read from track 2 of the swiped card.

### `Track3EncryptedData`

The encrypted data read from track 3 of the swiped card.

### `Track4EncryptedData`

The encrypted data read from track 4 of the swiped card.

### `Track1MaskedDataLength`

The amount of masked track 1 data, in bytes, that is stored in **Track1MaskedData[MSR_TRACK_SIZE]**.

### `Track2MaskedDataLength`

The amount of masked track 2 data, in bytes, that is stored in **Track2MaskedData[MSR_TRACK_SIZE]**.

### `Track3MaskedDataLength`

The amount of masked track 3 data, in bytes, that is stored in **Track3MaskedData[MSR_TRACK_SIZE]**.

### `Track4MaskedDataLength`

The amount of masked track 4 data, in bytes, that is stored in **Track4MaskedData[MSR_TRACK_SIZE]**.

### `Track1MaskedData`

The masked data read from track 1 of the swiped card.

### `Track2MaskedData`

The masked data read from track 2 of the swiped card.

### `Track3MaskedData`

The masked data read from track 3 of the swiped card.

### `Track4MaskedData`

The masked data read from track 4 of the swiped card.

### `Track1DiscretionaryDataLength`

The amount of discretionary track 1 data, in bytes, that is stored in **Track1DiscretionaryData[MSR_TRACK_SIZE]**.

### `Track2DiscretionaryDataLength`

The amount of discretionary track 2 data, in bytes, that is stored in **Track2DiscretionaryData[MSR_TRACK_SIZE]**.

### `Track1DiscretionaryData`

The amount of discretionary track 1 data, in bytes, that is stored in **Track1DiscretionaryData[MSR_TRACK_SIZE]**.

### `Track2DiscretionaryData`

The amount of discretionary track 2 data, in bytes, that is stored in **Track1DiscretionaryData[MSR_TRACK_SIZE]**.

### `CardAuthenicationDataLength`

The amount of encrypted card authentication data, in bytes, that is stored in **CardAuthenicationData[MSR_CARD_AUTHENTICATION_DATA_SIZE]**. May include padding.

### `CardAuthenticationDataAbsoluteLength`

The amount of card authentication data, in bytes, before encryption. This value may be used to remove padding on decryption.

### `CardAuthenicationData`

Authentication data read from the swiped card.

### `AdditionalSecurityInformationLength`

The amount of additional security information, in bytes, stored in **AdditionalSecurityInformation[MSR_ADDITIONAL_SECURITY_INFORMATION_SIZE]**.

### `AdditionalSecurityInformation`

Additional security information read from the swiped card.
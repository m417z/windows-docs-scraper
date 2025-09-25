# RECO_LATTICE_PROPERTY structure

## Description

Contains a property used in the lattice.

## Members

### `guidProperty`

GUID for the property value that is being assigned.

### `cbPropertyValue`

Length in bytes of the *pPropertyValue* byte array.

### `pPropertyValue`

Byte array that points to the property data.

## Remarks

Properties can be stored on a column or an element. For example, the recognizer can store ink line break information about an alternate.

There are some predefined property GUIDs defined in the Msinkaut.h header file.

| GUID | Description |
| --- | --- |
| INKRECOGNITIONPROPERTY_CONFIDENCELEVEL | Describes whether the element contains wide string or wide character data. `enum enumCONFIDENCE_LEVEL``{``CFL_STRONG = 0,``CFL_INTERMEDIATE = 1,``CFL_POOR = 2``} CONFIDENCE_LEVEL;` |
| INKRECOGNITIONPROPERTY_HOTPOINT | For gestures, identifies the part of the stroke that is the hot point. The hot point is the part of the stroke where the associated action is being applied. |
| INKRECOGNITIONPROPERTY_LINEMETRICS | Contains a [LATTICE_METRICS](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-lattice_metrics) structure that holds details about the baseline and midline for the element. To set this property, your recognizer must also set the INKRECOGNITIONPROPERTY_LINENUMBER property. |
| INKRECOGNITIONPROPERTY_LINENUMBER | A ULONG value containing the line that the element belongs to as determined by the recognizer. |

## See also

[RECO_LATTICE_COLUMN Structure](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_lattice_column)

[RECO_LATTICE_ELEMENT Structure](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_lattice_element)

[RECO_LATTICE_PROPERTIES Structure](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_lattice_properties)

[Recognizer Lattice Structure](https://learn.microsoft.com/windows/desktop/tablet/recognizer-lattice-structure)
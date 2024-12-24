# QMK Userspace

Using Github Actions to build firmware for my QMK boards:

- Keyboardio Atreus
- Preonic Rev 3 Drop

More or less a mirror of my ZMK layout: https://github.com/evantravers/zmk-config

Someday...

- Bancouver40 (for now, use my `qmk_firmware` branch as an override.)

```bash
nix shell nixpkgs#qmk
qmk config user.overlay_dir="~/src/github.com/evantravers/qmk_firmware/"
# you may need to qmk git-submodule in there
qmk compile -kb sporewoh/bancounver40 -km evantravers
```

## Features

- Combos in userspace
- Shared keymaps across three boards

## Related

- Pretty much all the clever stuff came from other people or Drashna.
- Previous history here: https://github.com/evantravers/qmk_firmware/commits/

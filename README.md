# SteelCadence

A Sekiro-inspired combat vertical slice in Unreal Engine 5 — deflect-driven melee built around posture, frame-accurate parry windows, and a boss with a real attack-pattern state machine.

> **Status:** in development. Currently at M1 — movement and traversal.

---

## What this project is

Not a game. A **vertical slice** demonstrating a single deeply-built system: timing-based melee combat where deflecting is the core verb rather than dodging.

The engineering focus is the combat layer:

- **Posture** as a second resource alongside health — deflects convert incoming damage into posture damage
- **Deflect windows** measured in frames, driven by animation notifies
- **Input buffering and cancel windows** so attack chains feel responsive rather than sticky
- **Perilous attacks** requiring a distinct response instead of a universal defence
- **Boss AI** that reacts to player posture and distance, punishes spam, and leaves deliberate openings

## Built with

- Unreal Engine 5.7 · C++
- Gameplay Ability System (GAS) for attributes, effects, and abilities
- Behavior Trees for boss logic

## Roadmap

| Milestone | Scope | Status |
|---|---|---|
| M1 | Movement and traversal — third-person character, grapple, custom CMC mode | In progress |
| M2 | Animation — locomotion state machine, attack/deflect montages, root motion | Not started |
| M3 | Combat core — posture, deflect windows, input buffering, hit-stop | Not started |
| M4 | Boss AI — attack-pattern state machine, phase transition | Not started |
| M5 | Specialization deep dive | Not started |
| M6 | Package — docs, video, playable build | Not started |

## Building

Requires Unreal Engine 5.7 and Visual Studio 2022 (Desktop development with C++).

```
git clone <repo-url>
cd SteelCadence
```

Right-click `SteelCadence.uproject` → **Generate Visual Studio project files**, then open `SteelCadence.sln` and build — or launch the `.uproject` directly and let the editor compile.

This repo uses **Git LFS** for `.uasset` and `.umap` files — run `git lfs install` once before cloning.

## Credits

Character and environment assets are Epic Games template/sample content. All gameplay systems code is my own.

Combat design is inspired by *Sekiro: Shadows Die Twice* (FromSoftware). This is an unaffiliated learning project.

# SteelCadence — Roadmap

Development tracking for the vertical slice. Each milestone ends in a git tag.

**Current milestone:** M1 — Movement and traversal
**Near-term target:** M3 (combat core) — the first genuinely demo-able point.

---

## M1 — Movement and traversal

- [ ] Third-person character implemented in C++ (not Blueprint-only)
- [ ] Grapple hook: target detection, travel arc, camera handling
- [ ] One custom movement mode via `UCharacterMovementComponent` (mantle / ledge grab)
- [ ] Sprint and jump tuned for combat pacing
- [ ] Read engine source — can explain `PerformMovement` and the CMC replication flow
- [ ] Tag `v0.1-movement`

## M2 — Animation

- [ ] Locomotion state machine + blendspace
- [ ] Attack montages with notify-driven hit windows
- [ ] Deflect, block, and hit-react montages with correct interrupt priority
- [ ] Root motion on attacks
- [ ] Thread-safe anim update on the locomotion path
- [ ] Tag `v0.2-anim`

## M3 — Combat core

The heart of the project.

- [ ] GAS `AttributeSet`: Health, Posture, PostureRegen, Stamina
- [ ] Attack abilities with startup / active / recovery frames driven by notifies
- [ ] Deflect window — timed parry converting incoming damage into posture damage
- [ ] Posture break → deathblow opportunity
- [ ] Perilous (unblockable) attacks requiring a distinct response
- [ ] Input buffering and cancel windows
- [ ] Hit-stop, screen shake, hit-pause tuning
- [ ] Tag `v0.3-combat`

## M4 — Boss AI

- [ ] Boss with a real attack-pattern state machine (not random selection)
- [ ] Reacts to player posture and distance; punishes spam; leaves deliberate openings
- [ ] Phase 2 transition at a posture/health threshold, with a changed moveset
- [ ] Tag `v0.4-boss`

## M5 — Specialization deep dive

Lane chosen at the end of M4.

- [ ] Lane: _TBD_ — animation programming, or combat systems/tooling
- [ ] Tag `v1.0`

## M6 — Package

- [ ] One dressed arena with a stealth-deathblow approach route
- [ ] `docs/architecture.md`
- [ ] `docs/combat-system.md` — posture math, deflect window timing, why those frame counts
- [ ] README with GIF
- [ ] 3-minute video with voice-over
- [ ] Packaged build on GitHub Releases

---

## Scope guardrails

Deliberate non-goals. Revisit only after M6.

- No original art — Epic template and sample content only
- No level design beyond one arena
- No menus, save system, settings, or dialogue
- One boss, not several

## Parking lot

Deferred, not dropped.

- Anthology framing: a D-Day FPS level and a Fez-style perspective-shift puzzle, as separate projects
- Multiplayer / client-side prediction — a better fit for a future project than for this one

---

## Notes to self

- The UE 5.7 template shipped `Source/SteelCadence/Variant_Combat/` — Epic's own combat reference, including `AnimNotify_CheckCombo`, `AnimNotify_DoAttackTrace`, and the `CombatAttacker` / `CombatDamageable` interfaces. Read it before writing new combat code.
- Engine source worth reading: `CharacterMovementComponent.cpp`, `AnimInstance.cpp`, `AbilitySystemComponent.cpp`

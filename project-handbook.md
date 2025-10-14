# Metrology Test Framework – Collaboration Handbook

This handbook is a quick reference for the core maintainers of the Metrology Test Framework. It captures how we coordinate day-to-day execution while pointing to the canonical contribution process documented in [`CONTRIBUTING.md`](CONTRIBUTING.md). Community contributors should start with the contributing guide; this document supplements it with context about how the core team stays aligned.

## How to Use This Handbook

1. **Read the canonical guides first.** The full workflow, coding standards, and review checklist live in [`CONTRIBUTING.md`](CONTRIBUTING.md). Build and architecture details are covered in [`DESIGN_DOCUMENT.md`](DESIGN_DOCUMENT.md).
2. **Use this document as a shared reference.** The sections below describe how we plan tasks, capture daily updates, and keep the collaboration rhythm healthy.

## 1. Task Planning and Status Tracking

Tasks are tracked in the repository's issue tracker, which serves as the single source of truth for ownership and progress. Use labels or project boards within the tracker to represent statuses such as ⏳ Not started, 🟡 In progress, 🔍 In review, and ✅ Done.

Please ensure the following:

- The issue tracker is updated promptly when work starts, pauses, or completes.
- Related discussions, dependencies, and hand-offs are captured directly on the issue so they remain discoverable.
- Reference the associated task or issue ID in commit messages and pull request descriptions to maintain traceability.

## 2. Daily Sync and Worklog Updates

- Update [`WORKLOG.md`](WORKLOG.md) before each commit or at the end of the day so teammates can follow progress. The file contains the authoritative template and examples.
- Surface blockers early—if you are waiting on feedback or an external dependency, document it in the worklog entry so the next reviewer can assist.
- When pairing or handing off a task, add a short note in the worklog so the incoming owner understands the latest state.

## 3. Collaboration Rhythm

- **Pull requests:** Confirm the checklist in [`CONTRIBUTING.md`](CONTRIBUTING.md#6-review-checklist) before requesting a review. Doing so keeps the review queue flowing smoothly.
- **Review rotation:** Aim to review at least one teammate’s pull request for every change you merge. Mention open questions in the pull request discussion rather than private channels so the project history remains discoverable.
- **Pairing and support:** If you are blocked for more than one working day, ask for help in the worklog or project chat and flag the issue in the relevant task.

## 4. Resource Index

- Design document: [`DESIGN_DOCUMENT.md`](DESIGN_DOCUMENT.md)
- Contribution guidelines: [`CONTRIBUTING.md`](CONTRIBUTING.md)
- Shared worklog template: [`WORKLOG.md`](WORKLOG.md)
- Repository README: [`README.md`](README.md)

Please keep this handbook up to date as workflows evolve. Consistent documentation ensures a smooth onboarding experience for all contributors.

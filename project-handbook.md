# Metrology Test Framework – Collaboration Handbook

This handbook outlines how contributors coordinate work on the Metrology Test Framework. It complements the design document and contributing guide with practical, day-to-day expectations.

## 1. Task Planning and Status Tracking

| Task ID | Description | Owner | Status | Notes |
|---------|-------------|-------|--------|-------|
| #001    | Example task description | —     | ⏳ Not started | Replace with project-specific tasks |

**Status legend:** ⏳ Not started · 🟡 In progress · 🔍 In review · ✅ Done.

- Document your active tasks in the repository issue tracker or shared planning board.
- Include the relevant task or issue ID in commit messages and pull request descriptions to keep traceability clear.

## 2. Git Workflow and Pull Requests

1. Create a topic branch for every change:
   ```bash
   git checkout -b feature/<short-description>
   ```
2. Write descriptive commit messages that capture the “why” as well as the “what”. Keep commits focused and logically scoped.
3. Update the shared `WORKLOG.md` file before each commit with a short note covering what changed, what is in progress, and any open questions.
4. Open a pull request when the branch is ready for review. Use the format:
   ```
   [Type] Brief summary (#TaskID)
   ```
   Examples: `[Feature] Add sensor mock (#014)`, `[Fix] Stabilize build on GCC 12 (#082)`.
5. Fill in the pull request template with:
   - A concise summary of the change.
   - Links to related tasks or issues.
   - Test evidence (command output, screenshots, etc.).
6. Request at least one reviewer and respond to all feedback (from humans or automated reviewers) before merging.

## 3. Coding and Review Checklist

Use this checklist before requesting a review:

- [ ] Names are intention-revealing (functions use verb phrases such as `calculateOffsets`).
- [ ] Error handling and logging paths are covered where applicable.
- [ ] New functionality includes accompanying Google Test unit tests.
- [ ] Documentation (README, design docs, inline comments) has been updated.
- [ ] `./run_tests.sh` completes successfully and its output is attached to the pull request.
- [ ] Known follow-ups or limitations are captured in issues or TODO comments.

## 4. Daily Worklog Template

Keep your teammates informed by logging progress. Use the template below when updating the shared worklog prior to each commit or at the end of the day:

```markdown
### <Your Name>'s log (YYYY/MM/DD)
- ✅ Completed: …
- 🟡 In progress: …
- 🤔 Blockers / questions: …
- ⏭️ Next steps: …
```

## 5. Resources

- Design document: [`DESIGN_DOCUMENT.md`](DESIGN_DOCUMENT.md)
- Contribution guidelines: [`CONTRIBUTING.md`](CONTRIBUTING.md)
- Repository README: [`README.md`](README.md)

Please keep this handbook up to date as workflows evolve. Consistent documentation ensures a smooth onboarding experience for all contributors.

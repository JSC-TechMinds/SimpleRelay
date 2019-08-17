# Contributing Rules
Thanks for your interest in contributing to this free open source project! We appreciate any help from the community.

## Issues
- Do you need help or have a question about using Arduino? Support requests should be made to the appropriate section of the [Arduino forum](http://forum.arduino.cc) rather than an issue report. **Issue reports are to be used to report bugs or make feature requests only.**
- Search [existing pull requests and issues](https://github.com/JSC-electronics/SimpleRelay/issues?q=) to be sure it hasn't already been reported. If you have additional information to provide about an existing issue then please comment on that issue.
- State the newest version of the Arduino IDE you have verified the issue with and which operating system you are using.
- If you are using this library on PlatformIO, report version of PlatformIO Core and which operating system you are using.
- The issue title should be concise yet descriptive. Vague titles make it difficult to know the purpose of the issue when looking through the list of reports and may cause your issue to not be given proper attention.
- Describe the issue and what behavior you were expecting. Post complete error messages using [Markdown code fencing](https://guides.github.com/features/mastering-markdown/#examples).
- Provide a full set of steps necessary to reproduce the issue. Demonstration code should be complete, correct, and simplified to the minimum amount of code necessary to reproduce the issue. Please use [Markdown code fencing](https://guides.github.com/features/mastering-markdown/#examples) when posting code.
- Be responsive. We may need you to provide more information, please respond as soon as possible.
- If you find a solution to your problem update your issue report with an explanation of how you were able to fix it and close the issue.

## Pull Requests
- Search [existing pull requests](https://github.com/JSC-electronics/SimpleRelay/pulls?q=) to see if one has already been submitted for this change. Search the [issues](https://github.com/JSC-electronics/SimpleRelay/issues?q=is%3Aissue) to see if there has been a discussion on this topic and whether your pull request can close any issues.
- Code formatting should be consistent with the style used in the existing code.
- Don't leave commented out code. A record of this code is already preserved in the commit history.
- All commits must be atomic. This means that the commit completely accomplishes a single task. Each commit should result in fully functional code. Multiple tasks should not be combined in a single commit, but a single task should not be split over multiple commits (e.g. one commit per file modified is not a good practice). For more information see http://www.freshconsulting.com/atomic-commits.
- Each pull request should address a single bug fix or enhancement. This may consist of multiple commits. If you have multiple, unrelated fixes or enhancements to contribute, submit them as separate pull requests.
- Commit messages:
  - Use the [imperative mood](http://chris.beams.io/posts/git-commit/#imperative) in the title. For example: "Apply editor indent preference"
  - Do not end the title with a period.
  - Separate title from the body with a blank line. If you're committing via GitHub or GitHub Desktop this will be done automatically.
  - Completely explain the purpose of the commit. Include a rationale for the change, any caveats, side-effects, etc.
  - If your pull request fixes an issue in the issue tracker, use the [closes/fixes/resolves syntax](https://help.github.com/articles/closing-issues-via-commit-messages) in the body to indicate this.
  - See http://chris.beams.io/posts/git-commit for more tips on writing good commit messages.
- Pull request title and description should follow the same guidelines as commit messages.
- Rebasing pull requests is OK and encouraged. After submitting your pull request some changes may be requested. Rather than adding unnecessary extra commits to the pull request, you can squash these changes into the existing commit and then do a force push to your fork. When you do a force push to your fork, the PR will be updated with your new changes, so there is no need to open a new PR to make changes. Leave a comment on the pull request thread to explain that the history has been changed. This will help to keep the commit history of the repository clean.
- Make sure your change does not break existing unit tests (see below for more details).
- After your pull request is merged please update the documentation if the changes require it:
  - Edit appropriate [Wiki pages](https://github.com/JSC-electronics/SimpleRelay/wiki).

## Testing the code
This library uses [Arduino CI](https://github.com/ianfixes/arduino_ci) as a unit test framework. When you create a pull request, your code will be tested against existing test cases. Sometimes it may be useful to test the code locally to save time. Please follow the instructions on Arduino CI page.

### Requirements
Requirements to build and run the unit tests:
- (Optional) Install [RVM](http://rvm.io/)
- Ruby version 2.2 or higher
- Bundler gem (install with `gem install bundler`)

### Setup
Clone SimpleRelay git repository:
```bash
git clone git@github.com:JSC-electronics/SimpleRelay.git
```

Install Ruby dependencies:
```bash
bundle install
```

Run automated tests:
```bash
bundle exec arduino_ci_remote.rb
```

Please check full [reference](https://github.com/ianfixes/arduino_ci/blob/master/REFERENCE.md) for more options, including running only selected tests.